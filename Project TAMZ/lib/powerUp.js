Quintus.powerUp = function (Q) {
    Q.component("powerUpControl", {
        added: function () {
            var entity = this.entity;
            entity.on("step", this, "step");

            entity.on("bump.bottom, bump.left, bump.right", function (collision) {
                if (collision.obj.isA("Player")) {
                    if (entity.p.powerUpType == 1) {
                        collision.obj.p.gunSet = entity.p.set;
                    } else if (entity.p.powerUpType == 2) {
                        collision.obj.p.blasterSpeed -= entity.p.speed;
                    }
                        entity.destroy();

                }
            });

        },
        step: function (dt) {
            this.entity.p.y += 4;
            if (this.entity.p.y > window.innerHeight + 80) {
                //console.log("powerUpOutOfScene");
                this.entity.del("enemyControl");
                this.entity.debind();
                this.entity.destroy();
            }
        }
    });

    Q.Sprite.extend("plusBlaster", {
        init: function (p) {
            this._super(p, {
                x: Math.floor(Math.random() * 180) + 80,
                y: -100,
                asset: 'plusBlaster.png',
                scale: 0.04,
                set: 1,
                powerUpType: 1,
                type: Q.SPRITE_POWERUP
            });
            this.add("2d, powerUpControl");
            this.p.angle = Math.floor(Math.random() * 360);
        }
    });

    Q.Sprite.extend("plusBlasterSpeed", {
        init: function (p) {
            this._super(p, {
                x: Math.floor(Math.random() * 180) + 80,
                y: -100,
                asset: 'plusBlasterSpeed.png',
                scale: 0.04,
                powerUpType: 2,
                speed: 20,
                type: Q.SPRITE_POWERUP
            });
            this.add("2d, powerUpControl");
            this.p.angle = Math.floor(Math.random() * 360);
        }
    });

}

