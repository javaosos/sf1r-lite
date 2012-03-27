///
/// @file   ConditionInfo.cpp 
/// @brief  Source file of Condition informative classes.
/// @author Dohyun Yun
/// @date   2008-06-05
/// @details
/// - Log
///     - 2009.08.10 All classes are commented except for PageInfo.

#include "ConditionInfo.h"

using namespace std;

namespace sf1r {

LanguageAnalyzerInfo::LanguageAnalyzerInfo(void): 
    applyLA_(false), 
    useOriginalKeyword_(false), 
    synonymExtension_(false)
{
}

void LanguageAnalyzerInfo::clear(void)
{
    applyLA_ = false;
    useOriginalKeyword_ = false;
    synonymExtension_ = false;
}

SearchingModeInfo::SearchingModeInfo(void):
    mode_(SearchingMode::DefaultSearchingMode),
    threshold_(0.0F)
{
}

void SearchingModeInfo::clear(void)
{
    mode_ = SearchingMode::DefaultSearchingMode;
    threshold_ = 0.0F;
}

} // end - namespace sf1r
