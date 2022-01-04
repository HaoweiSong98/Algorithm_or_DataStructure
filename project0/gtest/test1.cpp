#include "gtest/gtest.h"
#include "proj0.hpp"
#include <map>
#include <string>

namespace{

TEST(VerifySolution, First){
    std::string s1 = "POT";
    std::string s2 = "PAN";
    std::string s3 = "BIB";

    std::map<char, unsigned> solution = { {'A', 7}, {'B', 5}, 
        {'I', 0}, {'N', 4}, {'O', 3}, {'P', 2}, {'T', 1}
    };

    EXPECT_TRUE( verifySolution( s1, s2, s3, solution ) );
}

TEST(VerifySolution, Second){

    std::string s1 = "CAT";
    std::string s2 = "DOG";
    std::string s3 = "PIG";

    std::map<char, unsigned> solution = { {'A', 5}, {'C', 2}, {'D', 1}, {'G', 6}, {'I', 9}, {'O', 4}, {'P', 3}, {'T', 0} };

    EXPECT_TRUE( verifySolution( s1, s2, s3, solution ) );
} // end test two
TEST(VerifySolution, Third){
    std::string s1 = "AOA";
    std::string s2 = "BOB";
    std::string s3 = "CCCC";
    
    std::map<char, unsigned> solution = { {'A', 5}, {'B', 6}, 
        {'C', 1}, {'O', 0}
    };
    
    EXPECT_TRUE( verifySolution( s1, s2, s3, solution ) );
}

TEST(VerifySolution, Fourth){
    std::string s1 = "AOAD";
    std::string s2 = "BOBE";
    std::string s3 = "CCCFA";

    std::map<char, unsigned> solution = { {'A', 5}, {'B', 6}, 
        {'C', 1}, {'O', 0}, {'D', 7}, {'E', 8}, {'F', 2}
    };
    
    EXPECT_TRUE( verifySolution( s1, s2, s3, solution ) );
}
TEST(VerifySolution, Fifth){
    std::string s1 = "AOAD";
    std::string s2 = "BOBE";
    std::string s3 = "CCCFA";

    std::map<char, unsigned> solution = { {'A', 5}, {'B', 6}, 
        {'C', 1}, {'D', 7}, {'E', 8}, {'F', 2}
    };
    
    EXPECT_FALSE( verifySolution( s1, s2, s3, solution ) );
}

} // end namespace
