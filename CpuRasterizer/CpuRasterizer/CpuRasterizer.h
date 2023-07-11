#pragma once

#include <memory>

#include <directxtk/SimpleMath.h>

class CpuRenderPipeline;

class CpuRasterizer
{      
private:
    static std::shared_ptr<CpuRenderPipeline> gpu;

public:
    static void BindSharedMemory(std::shared_ptr<CpuRenderPipeline> renderPipeline);

    // �ﰢ���� �ϳ��� �׸��� �Լ�
    // Rasterize!
    static void DrawIndexedTriangle(const size_t& startIndex);

    static DirectX::SimpleMath::Vector2 ProjectWorldToRaster(DirectX::SimpleMath::Vector3 point);

    static float EdgeFunction(const DirectX::SimpleMath::Vector2& v0, const DirectX::SimpleMath::Vector2& v1, const DirectX::SimpleMath::Vector2& point);
};

