#!/usr/bin/python3
"""UTF-8 validation module."""


def validUTF8(data):
    """Return True if data is a valid UTF-8 encoding, else False."""
    expected_continuation = 0

    for value in data:
        byte = value & 0xFF

        if expected_continuation == 0:
            if (byte >> 7) == 0b0:
                continue
            if (byte >> 5) == 0b110:
                expected_continuation = 1
            elif (byte >> 4) == 0b1110:
                expected_continuation = 2
            elif (byte >> 3) == 0b11110:
                expected_continuation = 3
            else:
                return False
        else:
            if (byte >> 6) != 0b10:
                return False
            expected_continuation -= 1

    return expected_continuation == 0
