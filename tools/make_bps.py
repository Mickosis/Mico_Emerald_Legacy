#!/usr/bin/env python3
import sys
import zlib
import struct

def encode_vli(val):
    res = bytearray()
    while True:
        b = val & 0x7F
        val >>= 7
        if val == 0:
            res.append(0x80 | b)
            break
        res.append(b)
        val -= 1
    return bytes(res)

def create_bps(src_path, dst_path, out_path):
    with open(src_path, 'rb') as f:
        src = f.read()
    with open(dst_path, 'rb') as f:
        dst = f.read()

    src_len = len(src)
    dst_len = len(dst)

    out = bytearray(b'BPS1')
    out += encode_vli(src_len)
    out += encode_vli(dst_len)
    out += encode_vli(0) # metadata size

    i = 0
    while i < dst_len:
        # Check matching length with source at same offset
        match_len = 0
        while i + match_len < dst_len and i + match_len < src_len and src[i + match_len] == dst[i + match_len]:
            match_len += 1
        
        if match_len > 0:
            # SourceRead
            out += encode_vli((match_len - 1) << 2 | 0)
            i += match_len
            continue

        # Non-matching block (TargetRead)
        diff_len = 0
        while i + diff_len < dst_len:
            if i + diff_len < src_len and src[i + diff_len] == dst[i + diff_len]:
                if i + diff_len + 4 <= dst_len and i + diff_len + 4 <= src_len and src[i + diff_len:i + diff_len + 4] == dst[i + diff_len:i + diff_len + 4]:
                    break
            diff_len += 1

        out += encode_vli((diff_len - 1) << 2 | 1)
        out += dst[i : i + diff_len]
        i += diff_len

    src_crc = zlib.crc32(src) & 0xFFFFFFFF
    dst_crc = zlib.crc32(dst) & 0xFFFFFFFF
    out += struct.pack('<II', src_crc, dst_crc)
    patch_crc = zlib.crc32(out) & 0xFFFFFFFF
    out += struct.pack('<I', patch_crc)

    with open(out_path, 'wb') as f:
        f.write(out)
    print(f"Created {out_path} ({len(out)} bytes)")
    print(f"Source CRC32: {src_crc:08X}, Target CRC32: {dst_crc:08X}")

if __name__ == '__main__':
    if len(sys.argv) < 4:
        print("Usage: make_bps.py <source.gba> <target.gba> <output.bps>")
        sys.exit(1)
    create_bps(sys.argv[1], sys.argv[2], sys.argv[3])
