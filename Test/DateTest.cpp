//
// Created by casti on 04/10/2024.
//
#include <gtest/gtest.h>
#include "../Date.h"

TEST(DataTest, ConstructorTest) {
    Date data(15, 11, 2003);
    EXPECT_EQ(data.getGiorno(), 15);
    EXPECT_EQ(data.getMese(), 11);
    EXPECT_EQ(data.getAnno(), 2003);
}

TEST(DataTest, SettersTest) {
    Date data(11, 11, 2000);
    data.setMese(12);
    data.setGiorno(30);
    ASSERT_EQ(data, Date(30, 12, 2000));
    EXPECT_THROW(data.setMese(2), std::out_of_range);
    EXPECT_THROW(data.setAnno(15), std::out_of_range);
    EXPECT_THROW(data.setMese(13), std::out_of_range);
    EXPECT_THROW(data.setGiorno(2000), std::out_of_range);

}

TEST(DataTest, IsleapTest) {
    Date data(11, 9, 2001);
    EXPECT_FALSE(data.IsLeap(data.getAnno()));
    data.setAnno(2000);
    EXPECT_TRUE(data.IsLeap(data.getAnno()));

}

TEST(DataTest, EqualityDateTest) {
    Date date1(11, 2, 2003);
    Date date2(2, 2, 2003);

    ASSERT_FALSE(date1 == date2);
    date2.setGiorno(11);
    ASSERT_TRUE(date1 == date2);
}

TEST(DataTest, DateTest) {

    EXPECT_THROW(Date data(40, 11, 2012), std::out_of_range);
    EXPECT_THROW(Date data(32, 11, 2012), std::out_of_range);
    EXPECT_THROW(Date data(11, 13, 2012), std::out_of_range);
    EXPECT_THROW(Date data(11, 14, 2012), std::out_of_range);
    EXPECT_THROW(Date data(11, 11, 1000), std::out_of_range);
    EXPECT_THROW(Date data(11, 11, 3000), std::out_of_range);

}