#pragma once

#include "common_msg/bsm_msg/bsm_msg.pb.h"

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class ForwardCollision : public Scenario<BasicSafetyMessage> {
 public:
  ForwardCollision() = default;
  virtual ~ForwardCollision() = default;

  bool Init(const Config &conf);

  bool Condition(const impl::EgoImpl &ego_impl,
                 const impl::EnvImpl &env_impl) override;

  bool Notify(const BasicSafetyMessage &msg) override;

 private:
  bool IsSameLane(const ParticipantPtr &ego, const ParticipantPtr &other);

 private:
  double alert_distance_;
};

}  // namespace scenario
}  // namespace shudao
