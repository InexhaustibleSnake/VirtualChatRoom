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
    void SetMessage(const FText& MessageText);
    void SetPlayerName(const FText& PlayerName);

protected:
    void SetTextBlockText(UTextBlock* InTextBlock, const FText& Text);

    UPROPERTY(meta = (BindWidget))
    UTextBlock* PlayerNameTextBlock;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* MessageTextBlock;
};
