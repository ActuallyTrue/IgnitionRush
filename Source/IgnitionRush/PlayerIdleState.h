 //Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "State.h"
#include "CoreMinimal.h"


/**
 * 
 */
class IGNITIONRUSH_API PlayerIdleState : public State
{
public:
	PlayerIdleState(UPlayerStateMachine& machine, APlayerCharacter& player) : State(machine, player) {};
	~PlayerIdleState();

	virtual void Init(PlayerStateInput& stateInput) override;

	virtual void Enter(PlayerStateInput& stateInput) override;

	virtual void Exit(PlayerStateInput& stateInput) override;

	virtual void Tick(PlayerStateInput& stateInput, float DeltaTime) override;

	virtual void PhysicsTick(float SubstepDeltaTime, PlayerStateInput& stateInput) override;
};
