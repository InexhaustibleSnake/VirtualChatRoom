// This project is made for a test assignment

#pragma once

#include "CoreMinimal.h"
#include "UI/Widgets/VCRBaseWidget.h"
#include "VCRMenuItemWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnReturnSignature, UUserWidget*, PreviousWidget);

class UButton;
class UOverlay;

UCLASS()
class VIRTUALCHATROOM_API UVCRMenuItemWidget : public UVCRBaseWidget
{
    GENERATED_BODY()

public:
    virtual void NativeOnInitialized() override;

    void SetPreviousWidget(UUserWidget* Widget) { PreviousWidget = Widget; }

    const UUserWidget* GetPreviousWidget() const { return PreviousWidget; }

    FOnReturnSignature OnReturnSignature; 

protected:
    void OnReturnButtonClicked();

    UPROPERTY(meta = (BindWidget))
    UButton* Return;

    UPROPERTY()
    UUserWidget* PreviousWidget;
};
