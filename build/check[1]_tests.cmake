add_test([=[bruh_test.BasicAssertions]=]  /home/emmanuel/Neptune/build/check [==[--gtest_filter=bruh_test.BasicAssertions]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[bruh_test.BasicAssertions]=]  PROPERTIES WORKING_DIRECTORY /home/emmanuel/Neptune/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  check_TESTS bruh_test.BasicAssertions)
