#pragma once

#include <vector>

namespace winrt::UFCase
{

    template <class T, typename IntT = ULONG, class IEnumT>
    inline std::vector<winrt::com_ptr<T>> GetIEnumComPtrVector(winrt::com_ptr<IEnumT> pEnum)
    {
        std::vector<winrt::com_ptr<T>> v;

        IntT k;

        do
        {
            winrt::com_ptr<T> ptr;
            pEnum->Next(1, ptr.put(), &k);
            if (ptr)
                v.push_back(ptr);
        } while (k);

        return v;
    }

    template <class T, typename IntT = ULONG, class IEnumT>
    inline std::vector<T> GetIEnumStructVector(winrt::com_ptr<IEnumT> pEnum)
    {
        std::vector<T> v;
        IntT *pk = new IntT;
        T ptr;

        while (true)
        {
            [[maybe_unused]] HRESULT _hr = pEnum->Next(1, &ptr, pk);
            if (*pk)
                v.push_back(ptr);
            else
                break;
        }

        return v;
    }

    template <typename T, typename IntT = ULONG, class IEnumT>
    inline IntT GetIEnumSize(winrt::com_ptr<IEnumT> pEnumOrigin)
    {
        IntT sum = 0, factor = 1;

        winrt::com_ptr<IEnumT> pEnum;
        check_hresult(pEnumOrigin->Clone(pEnum.put()));

        if (E_NOTIMPL != pEnum->Skip(0))
        {
            while (true)
            {
                if (auto hr = pEnum->Skip(factor); hr == S_OK)
                {
                    sum += factor;
                    // be careful for overflow
                    factor *= 2;
                }
                else
                {
                    assert(hr == S_FALSE);
                    assert(factor > 1);
                    factor = std::max<IntT>(1, factor / 2);
                }
            }
        }
        else
        {
            // IEnumXXXX::Skip is not implemented
            // fallback to IEnumXXXX::Reset + IEnumXXXX::Next
            if constexpr (std::is_base_of<::IUnknown, T>::value)
            {
                IntT k;
                winrt::com_ptr<::IUnknown> pUnk;
                while (true)
                {
                    pEnum->Next(1, pUnk.put(), &k);
                    if (k)
                        sum++;
                    else
                        break;
                }
            }
            else
            {
                IntT k;
                T val;
                while (true)
                {
                    pEnum->Next(1, &val, &k);
                    if (k)
                        sum++;
                    else
                        break;
                }
            }
        }

        return sum;
    }

} // namespace winrt::UFCase
