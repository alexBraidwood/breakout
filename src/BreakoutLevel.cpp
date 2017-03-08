/*
 * File: BreakoutLevel.cpp.
 * Created by: Alex Braidwood.
 * Date: Mar 08, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */

// TODO(Alex): Test these methods

#include <BreakoutLevel.h>
#include <fstream>
#include <sstream>
#include <rapidjson.h>
#include <document.h>
#include <istreamwrapper.h>

using namespace breakout;


void Level::load(const std::string& fileName) {
    this->bricks.clear();
    int tileCode;

    std::string line;
    std::ifstream fstream(fileName);
    assert(fstream.is_open());

    rapidjson::IStreamWrapper isw(fstream);
    rapidjson::Document jsonDocument;
    jsonDocument.ParseStream(isw);

    std::vector<std::vector<int>> tileData;

    // TODO(Alex): Error? Not an array?
    for (auto& value : jsonDocument.GetArray()) {
        // TODO(Alex): Parse 2-D JSON Array into vector
    }
}
