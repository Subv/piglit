/*
 * Copyright (c) 2014 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 * Author: Neil Roberts <neil@linux.intel.com>
 */

#include "piglit-util-gl.h"

struct format {
	GLenum internalFormat;
	GLenum format;
	GLenum type;
	GLsizei texelSize;

	const char *internalFormatName;
	const char *formatName;
	const char *typeName;
};

#define DEF_FORMAT(internalFormatArg, formatArg, typeArg, texelSizeArg) \
	{                                                               \
		internalFormatArg,                                      \
		formatArg,                                              \
		typeArg,                                                \
		texelSizeArg,                                           \
		#internalFormatArg,                                     \
		#formatArg,                                             \
		#typeArg                                                \
	}

bool
test_format(GLenum internalFormat,
	    GLenum format,
	    GLenum type,
	    GLsizei texelSize);

bool
test_formats(const struct format *formats,
	     int n_formats);

/**
 * Creates a 1x1 texture with the one format and asserts that trying
 * to clear using another format results in GL_INVALID_OPERATION
 */
bool
test_invalid_format(GLenum internalFormat,
		    GLenum texImageFormat,
		    GLenum texImageType,
		    GLenum clearValueFormat,
		    GLenum clearValueType);
