// GENERATED BY npm build
// DO NOT MODIFY

#pragma once
#include <map>
#include <string>
#include <saucer/webview.hpp>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "resource.hpp"

namespace laochan::embedded
{
    auto read_resource(const int id)
    {
        auto* const res = FindResource(nullptr, MAKEINTRESOURCE(id), RT_RCDATA);
        if (!res) throw std::runtime_error{ "unable to load resource" };

        auto* const handle = LoadResource(nullptr, res);
        if (!handle) throw std::runtime_error{ "unable to load resource" };

        return std::span<const std::uint8_t>(reinterpret_cast<std::uint8_t*>(LockResource(handle)), SizeofResource(nullptr, res));
    }

    inline auto all()
    {
        std::map<std::string, saucer::embedded_file> rtn;

        rtn.emplace("favicon.ico", saucer::embedded_file{"image/vnd.microsoft.icon", read_resource(ID_ASSET_0)});

        auto root = read_resource(ID_ASSET_1);
        rtn.emplace("index.html", saucer::embedded_file{"text/html", root});
        rtn.emplace("", saucer::embedded_file{"text/html", root});

        rtn.emplace("assets/gitadora-cQ1BqJ9U.webm", saucer::embedded_file{"video/webm", read_resource(ID_ASSET_2)});
        rtn.emplace("assets/howler-CTWA-ZGT.js", saucer::embedded_file{"text/javascript", read_resource(ID_ASSET_3)});
        rtn.emplace("assets/iidx-BAOXvOlX.jpg", saucer::embedded_file{"image/jpeg", read_resource(ID_ASSET_4)});
        rtn.emplace("assets/index-BGCGHj6k.css", saucer::embedded_file{"text/css", read_resource(ID_ASSET_5)});
        rtn.emplace("assets/index-D1NvJlV7.js", saucer::embedded_file{"text/javascript", read_resource(ID_ASSET_6)});
        rtn.emplace("assets/moai-bg-BU2gdkgA.jpg", saucer::embedded_file{"image/jpeg", read_resource(ID_ASSET_7)});
        rtn.emplace("assets/msyhsb-CG5zefP1.woff2", saucer::embedded_file{"font/woff2", read_resource(ID_ASSET_8)});
        rtn.emplace("assets/num-BvRoq2n1.png", saucer::embedded_file{"image/png", read_resource(ID_ASSET_9)});
        rtn.emplace("assets/num-z0VsZKpR.mp3", saucer::embedded_file{"audio/mpeg", read_resource(ID_ASSET_10)});
        rtn.emplace("assets/sdvx-BIdRBwi8.jpg", saucer::embedded_file{"image/jpeg", read_resource(ID_ASSET_11)});
        rtn.emplace("assets/sgm-BpMyBNft.woff2", saucer::embedded_file{"font/woff2", read_resource(ID_ASSET_12)});

        return rtn;
    }
}