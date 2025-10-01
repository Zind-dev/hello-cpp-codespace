#pragma once
#include <array>
#include <cstddef>
#include <optional>
#include <utility>

template <typename T, std::size_t N>
class RingBuffer {
    static_assert(N > 0, "N must be > 0");
public:
    RingBuffer() = default;

    bool push(const T& v) {
        if (full()) return false;
        buf_[head_] = v;
        head_ = (head_ + 1) % N;
        ++count_;
        return true;
    }
    bool push(T&& v) {
        if (full()) return false;
        buf_[head_] = std::move(v);
        head_ = (head_ + 1) % N;
        ++count_;
        return true;
    }
    std::optional<T> pop() {
        if (empty()) return std::nullopt;
        T out = std::move(buf_[tail_]);
        tail_ = (tail_ + 1) % N;
        --count_;
        return out;
    }
    const T* peek() const {
        if (empty()) return nullptr;
        return &buf_[tail_];
    }

    bool empty() const noexcept { return count_ == 0; }
    bool full()  const noexcept { return count_ == N; }
    std::size_t size() const noexcept { return count_; }
    std::size_t capacity() const noexcept { return N; }

private:
    std::array<T, N> buf_{};
    std::size_t head_ = 0;  // next write
    std::size_t tail_ = 0;  // next read
    std::size_t count_ = 0; // items in buffer
};