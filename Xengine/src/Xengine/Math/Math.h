//
// Created by yuan on 10/26/22.
//

#ifndef XENGINEMAIN_MATH_H
#define XENGINEMAIN_MATH_H

#include <glm/glm.hpp>

namespace XEngine::Math {
    bool DecomposeTransform(const glm::mat4& transform, glm::vec3& outTranslation, glm::vec3& outRotation, glm::vec3& outScale);
}

#endif //XENGINEMAIN_MATH_H
