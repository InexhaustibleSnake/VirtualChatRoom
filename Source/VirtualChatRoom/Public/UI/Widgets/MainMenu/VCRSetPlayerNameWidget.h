// This project is made for a test assignment

#pragma once

#include "CoreMinimal.h"
#include "UI/Widgets/VCRBaseWidget.h"
#include "VCRSetPlayerNameWidget.generated.h"

class UEditableTextBox;
class UVCRMenuButton;

UCLASS()
class VIRTUALCHATROOM_API UVCRSetPlayerNameWidget : public UVCRBaseWidget
{
    GENERATED_BODY()

public:
    virtual void NativeOnInitialized();

protected:
    UFUNCTION()
    void SavePlayerName();

    FName GetTextBoxPlayerName() const;

    UPROPERTY(meta = (BindWidget))
    UEditableTextBox* SetNameTextBox;

    UPROPERTY(meta = (BindWidget))
    UVCRMenuButton* SaveNameButton;
};
