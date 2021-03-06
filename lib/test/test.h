/* copyright 2016 Apache 2 sddekit authors */

void sd_test_true(bool cond, const char *scond, const char *fname, int lineno, const char *func);

void sd_test_failed(const char *scond, const char *fname, int lineno);

void sd_test_assert_near(double expected, double actual, double tol, const char *fname, int lineno, const char *func);

int sd_test_report();

#define EXPECT_TRUE(cond) sd_test_true(cond, #cond, __FILE__, __LINE__, __func__)

#define EXPECT_EQ(l, r) EXPECT_TRUE((l)==(r))

#define EXPECT_EQF(l, r) {\
	EXPECT_TRUE((l)==(r));\
	if ((l)!=(r)) sd_log_debug("expected %f, got %f, diff = %g", l, r, (l) - (r));\
}

#define ASSERT_NEAR(l, r, tol) sd_test_assert_near(l, r, tol, __FILE__, __LINE__, __func__)

#define TEST(topic, name) void sd_test__ ## topic ## _ ## name ()
