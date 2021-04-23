#pragma once

namespace cringine::shaders
{
    class shader
    {
    public:
        explicit shader(unsigned int id);

        void use() const;

        void disuse() const;

        [[nodiscard]] unsigned int id() const;

    private:
        unsigned int m_id;
    };
} // namespace cringine::shaders
