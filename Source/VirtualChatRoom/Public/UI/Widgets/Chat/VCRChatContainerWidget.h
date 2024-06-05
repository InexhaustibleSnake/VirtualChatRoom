// This project is made for a test assignment

#pragma once

#include "CoreMinimal.h"
#include "UI/Widgets/VCRBaseWidget.h"
#include "VCRChatContainerWidget.generated.h"

class UScrollBox;
class UVCRChatSendBoxWidget;

UCLASS()
class VIRTUALCHATROOM_API UVCRChatContainerWidget : public UVCRBaseWidget
{
    GENERATED_BODY()

protected:
    UPROPERTY(meta = (BindWidget))
    UScrollBox* ChatBox;

    UPROPERTY(meta = (BindWidget))
    UVCRChatSendBoxWidget* VCRChatSendBoxWidget;
};
