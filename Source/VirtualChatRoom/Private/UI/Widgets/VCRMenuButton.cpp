// This project is made for a test assignment

#include "UI/Widgets/VCRMenuButton.h"

UVCRMenuButton::UVCRMenuButton()
{
    FVector4 ButtonBaseColor(0.025f, 0.025f, 0.025f, 0.75f);
    FLinearColor ButtonColor(ButtonBaseColor);

    BackgroundColor = ButtonColor;

    OnClicked.AddDynamic(this, &UVCRMenuButton::OnButtonClicked);
}

void UVCRMenuButton::OnButtonClicked()
{
    OnButtonClickedSignature.Broadcast(this);
}
