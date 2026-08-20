#!/usr/bin/env bash
set -e

# Fast local build script using Podman container
podman run --rm -v "$(pwd):/workspace" -w /workspace mico-emerald-builder make -j$(nproc) "$@"
