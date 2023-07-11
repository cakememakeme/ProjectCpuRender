#pragma once

#include <directxtk/SimpleMath.h>

#include <vector>
#include <memory>

#include "CpuRasterizer.h"

enum class ELightType
{
    Directional = 0,
    Point,
    Spot,
};

class Object;
class Mesh;
class Light;

// CPU로 구현한 렌더 파이프라인
class CpuRenderPipeline : public std::enable_shared_from_this<CpuRenderPipeline>
{
    friend class CpuRasterizer;

private:
    // 로직 단순화를 위한 메시 모델을 여기에 묶어둔다
    // @todo. instancing
    std::vector<std::shared_ptr<Mesh>> meshes;

public:
    CpuRenderPipeline();

    bool Initialize(const int bufferWidth, const int bufferHeight);

    void Reset();

    void SetObjects(std::shared_ptr<std::vector<std::shared_ptr<Object>>> receivedObjects);

    void SetLightType(const ELightType lightType);

    std::shared_ptr<std::vector<DirectX::SimpleMath::Vector4>> Process();

private:
    void drawMeshes();
    void copyToBuffer(const Mesh& mesh);
};

