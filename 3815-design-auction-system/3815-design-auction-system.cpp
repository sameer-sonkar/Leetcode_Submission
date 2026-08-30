class AuctionSystem {
public:
    map<pair<int, int>, int> m;
    map<int,set<pair<int, int>>> s;
    AuctionSystem() {
        m.clear();
        s.clear();
    }

    void addBid(int userId, int itemId, int bidAmount) {
        if (m.find({userId, itemId}) != m.end()) {
            s[itemId].erase({m[{userId, itemId}], userId});
        }
        s[itemId].insert({bidAmount, userId});
        m[{userId, itemId}] = bidAmount;
    }

    void updateBid(int userId, int itemId, int newAmount) {
        s[itemId].erase({m[{userId, itemId}], userId});
        s[itemId].insert({newAmount, userId});
        m[{userId, itemId}] = newAmount;
    }

    void removeBid(int userId, int itemId) {
        int amount = m[{userId, itemId}];
        s[itemId].erase({amount, userId});
    }

    int getHighestBidder(int itemId) {
        if (s[itemId].size() == 0)
            return -1;
        auto x = s[itemId].rbegin();
        return x->second;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */