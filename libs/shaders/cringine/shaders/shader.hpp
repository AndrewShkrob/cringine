#pragma once

namespace cringine::shaders
{
    class shader
    {
    public:
        void use() const;

        void disuse() const;

        [[nodiscard]] unsigned int id() const;

    private:
        unsigned int m_id;
    };
} // namespace cringine::shaders