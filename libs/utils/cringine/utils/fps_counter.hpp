#pragma once

#include <chrono>

using namespace std::literals;

namespace cringine::utils
{
    class fps_counter
    {
        static constexpr inline int MILLISECONDS_IN_SECOND = 1'000;
        using ms = std::chrono::duration<double, std::milli>;

    public:
        void tick()
        {
            auto current_time = time();
            m_delta_time = current_time - m_last_time;
            m_last_time = current_time;
        }

        [[nodiscard]] double delta_time() const
        {
            return m_delta_time;
        }

        [[nodiscard]] int fps() const
        {
            return static_cast<int>(1.0f / m_delta_time);
        }

        [[nodiscard]] double time() const
        {
            double time_in_ms = std::chrono::duration_cast<ms>(std::chrono::high_resolution_clock::now() - m_start_time).count();
            return time_in_ms / MILLISECONDS_IN_SECOND;
        }

    private:
        double m_delta_time = 0;
        double m_last_time = 0;
        std::chrono::high_resolution_clock::time_point m_start_time = std::chrono::high_resolution_clock::now();
    };
} // namespace cringine::utils
