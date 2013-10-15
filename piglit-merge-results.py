#!/usr/bin/env python
#
# Permission is hereby granted, free of charge, to any person
# obtaining a copy of this software and associated documentation
# files (the "Software"), to deal in the Software without
# restriction, including without limitation the rights to use,
# copy, modify, merge, publish, distribute, sublicense, and/or
# sell copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following
# conditions:
#
# This permission notice shall be included in all copies or
# substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY
# KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
# WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
# PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHOR(S) BE
# LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
# AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
# OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
# DEALINGS IN THE SOFTWARE.


import argparse
import sys
import os.path

sys.path.append(os.path.dirname(os.path.realpath(sys.argv[0])))
import framework.core as core


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("results",
                        metavar="<First Results File>",
                        nargs="*",
                        help="Space seperated list of results files")
    args = parser.parse_args()

    combined = core.load_results(args.results.pop(0))

    for resultsDir in args.results:
        results = core.load_results(resultsDir)

        for testname, result in results.tests.items():
            combined.tests[testname] = result

    combined.write(sys.stdout)


if __name__ == "__main__":
    main()
