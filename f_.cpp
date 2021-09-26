CREATE (d: doumei {name:'エリュシオン'})
CREATE (d1: doumei {name:'山桜'})
CREATE (d2: doumei {name:'ゆぐどらしる'})
CREATE (d3: doumei {name:'木陰のパン屋'})
CREATE (d4: doumei {name:'月夜の宴'})
CREATE (d5: doumei {name:'王者・暁'})
CREATE (d6: doumei {name:'かもねぎ'})
CREATE (d6: doumei {name:'しげ'})
CREATE (d6: doumei {name:'出入り自由'})
CREATE (d6: doumei {name:'暇人の本気'})

CREATE (d:Castle{name:'ケイヨウ',who:'木陰のパン屋'})
CREATE (d1:Castle{name:'コウノウ',who:'しげ'})
CREATE (d2:Castle{name:'ジョウヨウ',who:'ゆぐどらしる'})
CREATE (d3:Castle{name:'サイジョウ',who:'しげ'})

MATCH (m:doumei), (n:Castle) where m.name='月夜の宴' AND n.name = 'サイジョウ' CREATE (m)-[:attack]->(n)
MATCH (m:doumei), (n:Castle) where m.name='しげ' AND n.name = 'ジョウヨウ' CREATE (m)-[:attack]->(n)
MATCH (m:doumei), (n:Castle) where m.name='出入り自由' AND n.name = 'ケイヨウ' CREATE (m)-[:attack]->(n)
MATCH (m:doumei), (n:Castle) where m.name='月夜の宴' AND n.name = 'コウノウ' CREATE (m)-[:attack]->(n)

CREATE (d6: doumei {name:'暇人の本気'})
CREATE (d2:Castle{name:'エンジョウ',who:'かもねぎ'})
CREATE (d1:Castle{name:'ハンジョウ',who:'王者・暁'})

MATCH (m:doumei), (n:Castle) where m.name='かもねぎ' AND n.name = 'エンジョウ' CREATE (m)-[:attack]->(n)
MATCH (m:doumei), (n:Castle) where m.name='王者・暁' AND n.name = 'ハンジョウ' CREATE (m)-[:attack]->(n)

ハンジョウ belongs 王者・暁
CREATE (n)-[:attack]->(n)