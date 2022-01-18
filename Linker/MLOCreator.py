#!/usr/bin/python3
import os
import struct

def littleEndian(num) -> str:
    num_high = bin((num >> 16))[2:]
    while (len(num_high) < 16):
        num_high = "0" + num_high
    num_low = bin((num & 0xffff))[2:]
    while (len(num_low) < 16):
        num_low = "0" + num_low
    little_endian_str = num_low + num_high
    return little_endian_str

def main():
    out_file_path = "output/main.bin"
    file_size = os.path.getsize(out_file_path)
    raw_file = open(out_file_path,"rb")
    demo = struct.pack('<L', file_size)
    f = open("output/demo.MLO", "wb")
    f.write(demo)
    demo = struct.pack('<L', 0x402f0400)
    f.write(demo)
    f.write(raw_file.read())
    f.close()

if __name__ == "__main__":
    main()