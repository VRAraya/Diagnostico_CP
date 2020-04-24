SELECT c.name,
       c.start_date,
       AVG(ev.score),
       STDEV(ev.score),
       MIN(ev.score),
       MAX(ev.score)
FROM courses c,
     exams e,
     evaluations ev
WHERE ev.exam_fk = e.pk AND e.course_fk = c.pk
GROUP BY c.name, c.start_date;