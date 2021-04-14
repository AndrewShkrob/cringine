#pragma once

#include <vector>

namespace cringine::utils
{
    template<class Callback>
    class observer
    {
    public:
        using callback_ptr = Callback*;
        using callbacks_container = std::vector<callback_ptr>;
        using container_size_type = typename callbacks_container::size_type;

        template<class Observable>
        void add_observer(Observable* observable_ptr)
        {
            auto* callback = static_cast<callback_ptr>(observable_ptr);
            m_callbacks.push_back(callback);
        }

        template<class CallbackFunc, class... Args>
        void notify(CallbackFunc callback_func, Args&&... args)
        {
            container_size_type idx = 0;
            while (idx != m_callbacks.size()) {
                if (m_callbacks[idx] == nullptr) {
                    std::swap(m_callbacks[idx], m_callbacks.back());
                    m_callbacks.pop_back();
                } else {
                    (m_callbacks[idx]->*callback_func)(std::forward<Args>(args)...);
                    ++idx;
                }
            }
        }

    private:
        callbacks_container m_callbacks;
    };
} // namespace cringine::utils
