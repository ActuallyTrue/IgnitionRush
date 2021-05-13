// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerStateInput.h"
#include "PhysicsPublic.h"
#include "PlayerCharacter.h"
#include "PlayerStateMachine.generated.h"

class State;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class IGNITIONRUSH_API UPlayerStateMachine : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerStateMachine();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	TMap<FString, State*> stateMap;

	State* currentState;
	PlayerStateInput* stateInput;
	APlayerCharacter* player;

	bool stateChanged = false;

	void InitStateMap();
	void SetInitialState();
	void ChangeState(FString stateName);


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
