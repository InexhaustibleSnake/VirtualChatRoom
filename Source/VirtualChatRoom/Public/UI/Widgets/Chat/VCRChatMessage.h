// This project is made for a test assignment

#pragma once

#include "CoreMinimal.h"
#include "UI/Widgets/VCRBaseWidget.h"
#include "VCRChatMessage.generated.h"

class UTextBlock;

UCLASS()
class VIRTUALCHATROOM_API UVCRChatMessage : public UVCRBaseWidget
{
    GENERATED_BODY()

public:
    void SetMessage(FText& MessageText);
    void SetPlayerName(FText& PlayerName);

protected:
    void SetTextBlockText(UTextBlock* InTextBlock, FText& Text);

    UPROPERTY(meta = (BindWidget))
    UTextBlock* PlayerNameTextBlock;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* MessageTextBlock;
};
