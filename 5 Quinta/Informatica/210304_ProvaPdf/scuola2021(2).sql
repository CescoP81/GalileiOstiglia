-- phpMyAdmin SQL Dump
-- version 5.0.4
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Creato il: Mar 05, 2021 alle 08:27
-- Versione del server: 10.4.16-MariaDB
-- Versione PHP: 7.4.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `scuola2021`
--

-- --------------------------------------------------------

--
-- Struttura della tabella `meteo_stazioni`
--

CREATE TABLE `meteo_stazioni` (
  `id` int(10) UNSIGNED NOT NULL,
  `nome` varchar(20) NOT NULL,
  `posizione` varchar(20) NOT NULL,
  `anno_attivazione` char(4) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dump dei dati per la tabella `meteo_stazioni`
--

INSERT INTO `meteo_stazioni` (`id`, `nome`, `posizione`, `anno_attivazione`) VALUES
(1, 'Meteo1', 'Porta Garibaldi', '2008'),
(2, 'Meteo2', 'Piazzale Gramsci', '2002'),
(3, 'Meteo3', 'Lungo Lago Gonzaga', '2012');

-- --------------------------------------------------------

--
-- Struttura della tabella `meteo_temperature`
--

CREATE TABLE `meteo_temperature` (
  `id` int(10) UNSIGNED NOT NULL,
  `valore` float NOT NULL,
  `id_stazione` int(10) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dump dei dati per la tabella `meteo_temperature`
--

INSERT INTO `meteo_temperature` (`id`, `valore`, `id_stazione`) VALUES
(1, 20.6, 1),
(2, 22.5, 1),
(3, 24, 1),
(4, 26.8, 1),
(5, 1, 2),
(6, 2.8, 2),
(7, 10.4, 2),
(8, 12, 2),
(9, 26, 3),
(10, 28.6, 3),
(11, 30.4, 3),
(12, 33.8, 3),
(13, 29, 1);

--
-- Indici per le tabelle scaricate
--

--
-- Indici per le tabelle `meteo_stazioni`
--
ALTER TABLE `meteo_stazioni`
  ADD PRIMARY KEY (`id`);

--
-- Indici per le tabelle `meteo_temperature`
--
ALTER TABLE `meteo_temperature`
  ADD PRIMARY KEY (`id`),
  ADD KEY `id_stazione` (`id_stazione`);

--
-- AUTO_INCREMENT per le tabelle scaricate
--

--
-- AUTO_INCREMENT per la tabella `meteo_stazioni`
--
ALTER TABLE `meteo_stazioni`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT per la tabella `meteo_temperature`
--
ALTER TABLE `meteo_temperature`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=14;

--
-- Limiti per le tabelle scaricate
--

--
-- Limiti per la tabella `meteo_temperature`
--
ALTER TABLE `meteo_temperature`
  ADD CONSTRAINT `meteo_temperature_ibfk_1` FOREIGN KEY (`id_stazione`) REFERENCES `meteo_stazioni` (`id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
