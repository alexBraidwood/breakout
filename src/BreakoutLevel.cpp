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


void Level::load(const std::string& fileName, int levelWidth, int levelHeight, core::Resources& resourceBatch) {
    this->bricks.clear();
    int tileCode;

    std::string line;
    std::ifstream fstream(fileName);
    assert(fstream.is_open());

    rapidjson::IStreamWrapper isw(fstream);
    rapidjson::Document jsonDocument;
    jsonDocument.ParseStream(isw);
    auto levelObject = jsonDocument.FindMember("Level");
    auto levelArray = levelObject->value.GetArray();

    std::vector<std::vector<int>> tileData;

    for (rapidjson::SizeType i = 0; i < levelArray.Size(); ++i) {
        tileData.push_back(std::vector<int>());
        auto& rowVector = tileData[i];

        for (auto& brick : levelArray[i].GetArray()) {
            auto brickValue = brick.GetInt();
            tileData[i].push_back(brickValue);
        }
    }

    assert(tileData.size() > 0);
    this->init(tileData, levelWidth, levelHeight, resourceBatch);
}

void Level::init(const std::vector<std::vector<int>>& tileData, int levelWidth, int levelHeight, core::Resources& resourceBatch) {
    auto height = tileData.size();
    auto width = tileData[0].size();
    float unitWidth = levelWidth / static_cast<float>(width);
    float unitHeight = levelHeight / static_cast<float>(height*3);

    for (auto y = 0; y < height; ++y) {
        for (auto x = 0; x < width; ++x) {
            glm::vec2 pos(unitWidth * x, unitHeight * y);
            glm::vec2 size(unitWidth, unitHeight);

            if (tileData[y][x] == 1) {
                core::GameObject gameObject(std::string("brick" + std::to_string(y) + std::to_string(x)));
                gameObject.position = pos;
                gameObject.size = size;
                gameObject.color = glm::vec3(0.8f, 0.8f, 0.7f);
                gameObject.texture = resourceBatch.getTexture("solid_block");
                gameObject.isSolid = true;
                this->bricks.push_back(gameObject);
            }
            else if (tileData[y][x] > 1) {
                glm::vec3 color = glm::vec3(1.0f);

                switch(tileData[y][x]) {
                case 2: {
                    color = glm::vec3(0.2f, 0.6f, 1.f);
                } break;
                case 3: {
                    color = glm::vec3(0.0f, 0.7f, 0.f);
                } break;
                case 4: {
                    color = glm::vec3(0.8f, 0.8f, 0.4f);
                }
                case 5: {
                    color = glm::vec3(1.f, 0.5f, 0.f);
                }
                }

                core::GameObject gameObject(std::string("brick" + std::to_string(y) + std::to_string(x)));
                gameObject.position = pos;
                gameObject.size = size;
                gameObject.color = color;
                gameObject.texture = resourceBatch.getTexture("block");
                gameObject.isSolid = false;
                this->bricks.push_back(gameObject);
            }
        }
    }
}

void Level::draw(core::Resources& resourceBatch) {
    for (auto& brick : bricks) {
        if (!brick.destroyed) {
            brick.draw(resourceBatch);
        }
    }
}

bool Level::isComplete() {
    for (auto& brick : bricks) {
        if (!brick.isSolid && !brick.destroyed) {
            return false;
        }
    }
    return true;
}

Level::Level(const Level& other) {
    for (auto& brick : other.bricks) {
        this->bricks.push_back(brick);
    }
}