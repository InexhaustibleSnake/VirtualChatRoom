// This project is made for a test assignment

#pragma once

#include "CoreMinimal.h"
#include "UI/Widgets/VCRBaseWidget.h"
#include "VCRInGameHUDWidget.generated.h"

class UVCRChatContainerWidget;
class UVCRPlayersListWidget;

UCLASS()
class VIRTUALCHATROOM_API UVCRInGameHUDWidget : public UVCRBaseWidget
{
    GENERATED_BODY()

protected:
    UPROPERTY(meta = (BindWidget))
    UVCRChatContainerWidget* ChatWidget;

    UPROPERTY(meta = (BindWidget))
    UVCRPlayersListWidget* PlayersList;
};
