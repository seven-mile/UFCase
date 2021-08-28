#include "pch.h"
#include "FeaturesPage.xaml.h"
#if __has_include("FeaturesPage.g.cpp")
#include "FeaturesPage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::UFCase::implementation
{
    FeaturesPage::FeaturesPage()
    {
        InitializeComponent();
    }

    Windows::Foundation::Collections::IObservableVector<FeatureTreeElement> FeaturesPage::FeatureDataSource()
    {
        return m_source;
    }

    void FeaturesPage::OnNavigatedTo(const winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs& e)
    {
        if (auto val = e.Parameter().try_as<source_t>()) {
            m_source = val;
        } else {
            throw winrt::hresult_invalid_argument();
        }
    }

}

