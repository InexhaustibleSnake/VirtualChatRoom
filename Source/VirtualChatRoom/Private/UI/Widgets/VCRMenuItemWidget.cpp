// This project is made for a test assignment

#include "UI/Widgets/VCRMenuItemWidget.h"
#include "Components/Button.h"

void UVCRMenuItemWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (Return)
    {
        Return->OnClicked.AddDynamic(this, &UVCRMenuItemWidget::OnReturnButtonClicked);
    }
}

void UVCRMenuItemWidget::OnReturnButtonClicked() 
{
    OnReturnSignature.Broadcast(PreviousWidget);
}
