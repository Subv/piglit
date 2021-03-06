/*
 * Copyright © 2017 Miklós Máté
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
 */

/**
 * Tests API for GL_ATI_fragment_shader: shader pass beginning with alpha instruction.
 */

#include "piglit-util-gl.h"

PIGLIT_GL_TEST_CONFIG_BEGIN

	config.supports_gl_compat_version = 10;
	config.window_visual = PIGLIT_GL_VISUAL_DOUBLE | PIGLIT_GL_VISUAL_RGBA;

PIGLIT_GL_TEST_CONFIG_END

enum piglit_result
piglit_display(void)
{
	/* UNREACHED */
	return PIGLIT_FAIL;
}

void
piglit_init(int argc, char **argv)
{
	bool pass = true;

	piglit_require_extension("GL_ATI_fragment_shader");

	/* Create a shader pass beginning with an alpha instruction */

	glBeginFragmentShaderATI();
	glAlphaFragmentOp1ATI(GL_MOV_ATI, GL_REG_0_ATI, GL_NONE,
			GL_PRIMARY_COLOR_ARB, GL_NONE, GL_NONE);
	pass &= piglit_check_gl_error(GL_NO_ERROR);
	glEndFragmentShaderATI();
	pass &= piglit_check_gl_error(GL_NO_ERROR);

	glBeginFragmentShaderATI();
	glColorFragmentOp1ATI(GL_MOV_ATI, GL_REG_0_ATI, GL_NONE, GL_NONE,
			GL_REG_1_ATI, GL_NONE, GL_NONE);
	glPassTexCoordATI(GL_REG_0_ATI, GL_REG_0_ATI, GL_SWIZZLE_STR_ATI);
	glAlphaFragmentOp1ATI(GL_MOV_ATI, GL_REG_0_ATI, GL_NONE,
			GL_PRIMARY_COLOR_ARB, GL_NONE, GL_NONE);
	pass &= piglit_check_gl_error(GL_NO_ERROR);
	glEndFragmentShaderATI();
	pass &= piglit_check_gl_error(GL_NO_ERROR);

	piglit_report_result(pass ? PIGLIT_PASS : PIGLIT_FAIL);
}
