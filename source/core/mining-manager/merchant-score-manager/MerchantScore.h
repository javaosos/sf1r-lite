///
/// @file MerchantScore.h
/// @brief the classes for merchant score, and category score
/// @author Jun Jiang <jun.jiang@izenesoft.com>
/// @date Created 2012-05-11
///

#ifndef SF1R_MERCHANT_SCORE_H
#define SF1R_MERCHANT_SCORE_H

#include <common/inttypes.h>
#include <3rdparty/febird/io/DataIO.h>
#include "../group-manager/GroupParam.h"

#include <string>
#include <map>
#include <vector>

using namespace febird;

namespace sf1r
{
using faceted::category_id_t;
using faceted::merchant_id_t;

template <typename CategoryT>
struct CategoryScore
{
    typedef typename std::map<CategoryT, score_t> CategoryScoreMap;
    CategoryScoreMap categoryScoreMap;

    /**
     * if no category is found in @c categoryScoreMap,
     * the @c generalScore would be used.
     */
    score_t generalScore;

    CategoryScore() : generalScore(0) {}

    DATA_IO_LOAD_SAVE(CategoryScore, &categoryScoreMap &generalScore);
};

template <typename MerchantT, typename CategoryT>
struct MerchantScoreMap
{
    typedef typename std::map<MerchantT, CategoryScore<CategoryT> > map_t;
    map_t map;

    DATA_IO_LOAD_SAVE(MerchantScoreMap, &map);
};

/// CategoryScore id version
typedef CategoryScore<category_id_t> CategoryIdScore;

/// Category string path from root to leaf node
typedef std::vector<std::string> CategoryStrPath;

/// CategoryScore string version
typedef CategoryScore<CategoryStrPath> CategoryStrScore;

/// MerchantScoreMap id version
typedef MerchantScoreMap<merchant_id_t, category_id_t> MerchantIdScoreMap;

/// MerchantScoreMap string version
typedef MerchantScoreMap<std::string, CategoryStrPath> MerchantStrScoreMap;

} // namespace sf1r

#endif // SF1R_MERCHANT_SCORE_H
