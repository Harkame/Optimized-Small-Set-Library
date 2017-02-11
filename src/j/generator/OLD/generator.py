#!/usr/bin/env python3
# -*- encoding: utf-8 -*-

"""A Simple code générator

Usage:
    generator -t <template> <number>
    tbdl -h | --help
    tbdl --version


Options:
    -h --help          Show this screen
    --version          Show version
    -id                Start from this id
"""

def main():
    """
    Main function, call parse_url
    """
    signal.signal(signal.SIGINT, signal_handler)
    global offset
    global arguments

    # Parse argument
    arguments = docopt(__doc__, version='v0.0.1')

    


def signal_handler(signal, frame):
    """
    Handle Keyboardinterrupt
    """
    logger.newline()
    logger.info('Good bye!')
    sys.exit(0)

if __name__ == '__main__':
    main()