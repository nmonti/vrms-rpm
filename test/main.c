/**
 * vrms-rpm - list non-free packages on an rpm-based Linux distribution
 * Copyright (C) 2021 Artur "suve" Iwicki
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 3,
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program (LICENCE.txt). If not, see <http://www.gnu.org/licenses/>.
 */

// The arg/def/jmp includes are required by cmocka.
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

extern void test__chainbuffer(void **state);
extern int test_setup__chainbuffer(void **state);
extern int test_teardown__chainbuffer(void **state);

extern void test__rebuffer(void **state);
extern int test_setup__rebuffer(void **state);
extern int test_teardown__rebuffer(void **state);

extern void test__licences(void **state);
extern int test_setup__licences(void **state);
extern int test_teardown__licences(void **state);

extern void test__compare_versions(void **state);
extern void test__replace_unicode_spaces(void **state);
extern void test__str_compare_with_null_check(void **state);
extern void test__str_findmultiple(void **state);
extern void test__str_starts_with(void **state);
extern void test__str_ends_with(void **state);
extern void test__str_split(void **state);
extern void test__trim(void **state);

int main(int argc, char **argv) {
	(void)(argc);

	const struct CMUnitTest tests[] = {
		cmocka_unit_test_setup_teardown(test__chainbuffer, test_setup__chainbuffer, test_teardown__chainbuffer),
		cmocka_unit_test_setup_teardown(test__rebuffer, test_setup__rebuffer, test_teardown__rebuffer),
		{ .name = "test__licences", .initial_state = argv[0], .test_func = test__licences, .setup_func = test_setup__licences, .teardown_func = test_teardown__licences },
		cmocka_unit_test(test__compare_versions),
		cmocka_unit_test(test__replace_unicode_spaces),
		cmocka_unit_test(test__str_compare_with_null_check),
		cmocka_unit_test(test__str_findmultiple),
		cmocka_unit_test(test__str_starts_with),
		cmocka_unit_test(test__str_ends_with),
		cmocka_unit_test(test__str_split),
		cmocka_unit_test(test__trim),
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
