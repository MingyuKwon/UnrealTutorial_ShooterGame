// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "kismet/GameplayStatics.h"

void UBTService_PlayerLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	APawn* playerCharacter = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (playerCharacter)
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), playerCharacter->GetActorLocation());
	}
}

UBTService_PlayerLocation::UBTService_PlayerLocation()
{
	NodeName = TEXT("Set Player Location");
}
