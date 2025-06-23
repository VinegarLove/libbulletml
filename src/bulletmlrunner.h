#ifndef BULLETRUNNER_H_
#define BULLETRUNNER_H_

#include "bulletmltree.h"
#include "bulletmlcommon.h"

#include <vector>
#include <memory>

class BulletMLParser;
class BulletMLNode;
class BulletMLRunnerImpl;

typedef std::vector<float> BulletMLParameter;

/// BulletMLRunner 状態クラス
class BulletMLState {
public:
	DECLSPEC BulletMLState(BulletMLParser* bulletml,
						   const std::vector<BulletMLNode*>& node,
						   std::shared_ptr<BulletMLParameter> para)
		: bulletml_(bulletml), node_(node.begin(), node.end()), para_(std::move(para)) {}

	DECLSPEC BulletMLParser* getBulletML() { return bulletml_; }
	DECLSPEC const std::vector<BulletMLNode*>& getNode() const { return node_; }
	DECLSPEC std::shared_ptr<BulletMLParameter> getParameter() { return para_; }

private:
	BulletMLParser* bulletml_;
	std::vector<BulletMLNode*> node_;
	std::shared_ptr<BulletMLParameter> para_;
};

class BulletMLRunner {
public:
	DECLSPEC explicit BulletMLRunner(BulletMLParser* bulletml);
    DECLSPEC explicit BulletMLRunner(BulletMLState* state);
    DECLSPEC virtual ~BulletMLRunner();

	DECLSPEC void run();

public:
	DECLSPEC bool isEnd() const;

public:
	// 以下は仮想関数群です。必要に応じて派生クラスで実装します。
	DECLSPEC virtual float getBulletDirection() = 0;
	DECLSPEC virtual float getAimDirection() = 0;
	DECLSPEC virtual float getBulletSpeed() = 0;
	DECLSPEC virtual float getDefaultSpeed() = 0;
	DECLSPEC virtual float getRank() = 0;
	DECLSPEC virtual void createSimpleBullet(float direction, float speed) = 0;
	DECLSPEC virtual void createBullet(BulletMLState* state, float direction, float speed) = 0;
	DECLSPEC virtual int getTurn() = 0;
	DECLSPEC virtual void doVanish() = 0;

	DECLSPEC virtual void doChangeDirection(float) {}
	DECLSPEC virtual void doChangeSpeed(float) {}
	DECLSPEC virtual void doAccelX(float) {}
	DECLSPEC virtual void doAccelY(float) {}
	DECLSPEC virtual float getBulletSpeedX() { return 0; }
	DECLSPEC virtual float getBulletSpeedY() { return 0; }
	DECLSPEC virtual float getRand() { return (float)rand() / RAND_MAX; }

private:
	DECLSPEC virtual BulletMLRunnerImpl* makeImpl(BulletMLState* state);

protected:
	std::vector<BulletMLRunnerImpl*> impl_;
};

#endif // ! BULLETRUNNER_H_
