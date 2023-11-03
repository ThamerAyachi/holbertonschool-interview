#!/usr/bin/python3
"""0. UTF-8 Validation"""


def validUTF8(data):
    remaining_bytes = 0

    for byte in data:
        if remaining_bytes > 0:
            if (byte & 0b11000000) != 0b10000000:
                return False
            remaining_bytes -= 1
        else:
            if byte & 0b10000000 == 0:
                remaining_bytes = 0
            elif byte & 0b11100000 == 0b11000000:
                remaining_bytes = 1
            elif byte & 0b11110000 == 0b11100000:
                remaining_bytes = 2
            elif byte & 0b11111000 == 0b11110000:
                remaining_bytes = 3
            else:
                return False

    return remaining_bytes == 0
