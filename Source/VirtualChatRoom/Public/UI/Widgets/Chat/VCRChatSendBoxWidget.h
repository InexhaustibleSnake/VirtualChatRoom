// This project is made for a test assignment

#pragma once

#include "CoreMinimal.h"
#include "UI/Widgets/VCRBaseWidget.h"
#include "VCRChatSendBoxWidget.generated.h"

class UEditableTextBox;
class UVCRMenuButton;

UCLASS()
class VIRTUALCHATROOM_API UVCRChatSendBoxWidget : public UVCRBaseWidget
{
    GENERATED_BODY()
public:
    virtual void NativeOnInitialized();

protected:
    void SendMessage();

    FText GetMessageText() const;

    UPROPERTY(meta = (BindWidget))
    UEditableTextBox* ChatSendTextBlock;

    UPROPERTY(meta = (BindWidget))
    UVCRMenuButton* SendTextButton;
};
