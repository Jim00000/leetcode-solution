#include "solution.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <vector>

class Vanilla : public ::testing::Test
{
  protected:
    std::vector<int> answer;
    int returnSize;

    void SetUp() override
    {
        returnSize = 0;
        answer.clear();
    }

    void TearDown() override
    {
        returnSize = 0;
        answer.clear();
    }
};

TEST_F(Vanilla, testcase1)
{
    answer = {0, 9};
    char *s = "barfoothefoobarman";
    char *words[] = {"foo", "bar"};
    constexpr int wordsSize = sizeof(words) / sizeof(words[0]);
    int *indices = findSubstring(s, words, wordsSize, &returnSize);
    const std::vector<int> result(indices, indices + returnSize);
    EXPECT_EQ(answer, result);
}

TEST_F(Vanilla, testcase2)
{
    answer = {};
    char *s = "wordgoodgoodgoodbestword";
    char *words[] = {"word", "good", "best", "word"};
    constexpr int wordsSize = sizeof(words) / sizeof(words[0]);
    int *indices = findSubstring(s, words, wordsSize, &returnSize);
    const std::vector<int> result(indices, indices + returnSize);
    EXPECT_EQ(answer, result);
}

TEST_F(Vanilla, testcase3)
{
    answer = {6, 9, 12};
    char *s = "barfoofoobarthefoobarman";
    char *words[] = {"bar", "foo", "the"};
    constexpr int wordsSize = sizeof(words) / sizeof(words[0]);
    int *indices = findSubstring(s, words, wordsSize, &returnSize);
    const std::vector<int> result(indices, indices + returnSize);
    EXPECT_EQ(answer, result);
}

TEST_F(Vanilla, testcase4)
{
    answer = {0, 1, 2, 3};
    char *s = "aaaaa";
    char *words[] = {"a", "a"};
    constexpr int wordsSize = sizeof(words) / sizeof(words[0]);
    int *indices = findSubstring(s, words, wordsSize, &returnSize);
    const std::vector<int> result(indices, indices + returnSize);
    EXPECT_EQ(answer, result);
}

TEST_F(Vanilla, testcase5)
{
    answer = {};
    char *s = "";
    char *words[] = {"a", "b", "c"};
    constexpr int wordsSize = sizeof(words) / sizeof(words[0]);
    int *indices = findSubstring(s, words, wordsSize, &returnSize);
    const std::vector<int> result(indices, indices + returnSize);
    EXPECT_EQ(answer, result);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}