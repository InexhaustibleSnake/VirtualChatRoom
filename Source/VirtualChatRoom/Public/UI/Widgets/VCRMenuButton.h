// This project is made for a test assignment

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "VCRMenuButton.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnButtonClickedSignature, UVCRMenuButton*);

UCLASS()
class VIRTUALCHATROOM_API UVCRMenuButton : public UButton
{
    GENERATED_BODY()

public:
    UVCRMenuButton();

    FOnButtonClickedSignature OnButtonClickedSignature;

protected:
    UFUNCTION()
    void OnButtonClicked();
};
