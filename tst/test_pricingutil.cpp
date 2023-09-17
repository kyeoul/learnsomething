#include <gtest/gtest.h>
#include "pricingutil.h"

TEST(PricingUtilTest, PricingInit){
    PricingUtil pricingUtil;

    EXPECT_NEAR(pricingUtil.getVal(), 0, 1e-4);
}

TEST(PricingUtilTest, PricingCalcTest) {
    PricingUtil pricingUtil;

    pricingUtil.calcVal(4.0, 0.04, 3);

    EXPECT_NEAR(pricingUtil.getVal(), 11.28, 1e-4);

    pricingUtil.calcVal(29.99, 0.09, 1.29);

    EXPECT_NEAR(pricingUtil.calcVal(29.99, 0.09, 1.29), 38.300229, 1e-4);
}