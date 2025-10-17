#include <iostream>
#include <vector>
#include <fstream>

enum class EStringPrimitive : uint
{
  SP_UNKNOWN,
  SP_PUNCH,
  SP_KICK,
  SP_GRAB,
  SP_COUNTER,
  SP_MAX,
};

/* RNG */
enum class EHitModifier : uint
{
  HM_UNKNOWN,
  HM_CRIT,
  HM_STAGGER,
  HM_MAX,
};

struct FComboStringMember
{
  EStringPrimitive           MoveIdentifier;
  int                        Hash;
  float                      Damage;
  std::vector<EHitModifier>  Modifiers;
  float                      Offset;
  float                      AnimationStagger;
};

/* These can be monostates */

/* Weapons have */
/*    * Stats                        */
/*    * Damage                       */
/*    * Modifiers                    */
/*    * Combos                       */
/*    * Upgrade Trees                */


class FWeapon
{

public: 
  using     Moveset            = std::vector<std::vector<FComboStringMember>>;
using     EvolutionTree      = std::vector<const FWeapon*>;

};

class SanguineLeer  : public FWeapon
{
public:

  const static Moveset         Moves ;

  const static EvolutionTree   Evolutions;

};

const SanguineLeer::Moveset SanguineLeer::Moves = std::vector<std::vector<FComboStringMember>>
{
  {
    FComboStringMember{
      .MoveIdentifier     = EStringPrimitive::SP_KICK,
      .Hash               = 0,
      .Damage             = 32,
      .Modifiers          = {EHitModifier::HM_CRIT, EHitModifier::HM_STAGGER},
      .Offset             = 0.0f,
      .AnimationStagger   = 0.0f
    },

    FComboStringMember{
      .MoveIdentifier     = EStringPrimitive::SP_PUNCH,
      .Hash               = 0,
      .Damage             = 32,
      .Modifiers          = {EHitModifier::HM_CRIT, EHitModifier::HM_STAGGER},
      .Offset             = 0.0f,
      .AnimationStagger   = 0.0f
    },
    FComboStringMember{
      .MoveIdentifier     = EStringPrimitive::SP_PUNCH,
      .Hash               = 0,
      .Damage             = 32,
      .Modifiers          = {EHitModifier::HM_CRIT, EHitModifier::HM_STAGGER},
      .Offset             = 0.0f,
      .AnimationStagger   = 0.0f
    }
  },

  {
    FComboStringMember{
      .MoveIdentifier     = EStringPrimitive::SP_PUNCH,
      .Hash               = 0,
      .Damage             = 32,
      .Modifiers          = {EHitModifier::HM_CRIT, EHitModifier::HM_STAGGER},
      .Offset             = 0.0f,
      .AnimationStagger   = 0.0f
    },

    FComboStringMember{
      .MoveIdentifier     = EStringPrimitive::SP_PUNCH,
      .Hash               = 0,
      .Damage             = 32,
      .Modifiers          = {EHitModifier::HM_CRIT, EHitModifier::HM_STAGGER},
      .Offset             = 0.0f,
      .AnimationStagger   = 0.0f
    },
    FComboStringMember{
      .MoveIdentifier     = EStringPrimitive::SP_PUNCH,
      .Hash               = 0,
      .Damage             = 32,
      .Modifiers          = {EHitModifier::HM_CRIT, EHitModifier::HM_STAGGER},
      .Offset             = 0.0f,
      .AnimationStagger   = 0.0f
    }
  },
};

class Bloodsong : public FWeapon
{


public:
  static const Bloodsong* GetInstance() 
  {
    const Bloodsong* b = new Bloodsong();
    return b;
  }

  const static Moveset         Moves ;
  const static EvolutionTree   Evolutions;
};

class VermillionMaw : public FWeapon
{

public:
  static const VermillionMaw* GetInstance() 
  {
    const VermillionMaw* v = new VermillionMaw();
    return v;
  }

  const static Moveset         Moves ;
  const static EvolutionTree   Evolutions;

};

std::ostream& operator<<(std::ostream& o, EStringPrimitive e)
{
  using enum EStringPrimitive;
  switch (e) {
    case SP_UNKNOWN:
      o << "Unknown " ;
    case SP_PUNCH:
      o << "Punch " ;
    break;
    case SP_KICK:
      o << "Kick " ;
    break;
    case SP_GRAB:
      o << "Grab " ;
    break;
    case SP_COUNTER:
      o << "Counter " ;
    break;
    case SP_MAX:
    break;
  }
  return o;
}

const FWeapon::EvolutionTree SanguineLeer::Evolutions = std::vector<const FWeapon*>
{
  Bloodsong::GetInstance(),
  VermillionMaw::GetInstance()
};


int main (int argc, char *argv[]) 
{
  /* "Serializing" a vector involves "Serializing" the underying array. */
  return 0;
}
