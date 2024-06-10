-- Q1: Selezionare tutti gli animali presenti nel database.
SELECT *
FROM Animale;

-- Q2: Selezionare tutti gli animali di con più di 10 anni.
SELECT *
FROM Animale
WHERE anni>=10;

-- Q3: Selezionare nome, razza, paese di provenienza di tutti gli animali, ordinato per paese.
SELECT nome, razza, paeseDiProvenienza
FROM Animale
ORDER BY paeseDiProvenienza ASC;

-- Q4: Selezionare tutti gli animali assegnati allo zoo di Bussolengo.
SELECT *
FROM Animale
WHERE zooAssegnato='Bussolengo';

-- Q5: Selezionare tutti gli animali provenienti dall'Asia ordinati per anni.
SELECT *
FROM Animale
WHERE paeseDiProvienienza='Asia'
ORDER BY anni ASC;