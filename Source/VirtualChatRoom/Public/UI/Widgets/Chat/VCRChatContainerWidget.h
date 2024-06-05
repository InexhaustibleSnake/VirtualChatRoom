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

public:
    UVCRChatContainerWidget();

    void AddMessage(const FString& PlayerName, const FString& Message);

protected:
    UPROPERTY(meta = (BindWidget))
    UScrollBox* ChatBox;

    UPROPERTY(meta = (BindWidget))
    UVCRChatSendBoxWidget* VCRChatSendBoxWidget;

    TSubclassOf<UUserWidget> MessageWidget;
};
