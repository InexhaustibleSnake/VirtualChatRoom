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

protected:
    UPROPERTY(meta = (BindWidget))
    UTextBlock* PlayerName;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* Message;
};
