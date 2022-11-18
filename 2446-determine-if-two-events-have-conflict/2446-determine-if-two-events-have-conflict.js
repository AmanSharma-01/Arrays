/**
 * @param {string[]} event1
 * @param {string[]} event2
 * @return {boolean}
 */
var haveConflict = function(event1, event2) {
    let [startHour1, startMin1] = event1[0].split(':');
    let [endHour1, endMin1] = event1[1].split(':');
    let [startHour2, startMin2] = event2[0].split(':');
    let [endHour2, endMin2] = event2[1].split(':');
    
    let s1 = parseInt(startHour1)*60 + parseInt(startMin1);
    let e1 = parseInt(endHour1)*60 + parseInt(endMin1);
    let s2 = parseInt(startHour2)*60 + parseInt(startMin2);
    let e2 = parseInt(endHour2)*60 + parseInt(endMin2);
    
    if(s1 <= s2 && s2 <= e1) return true;
    if(s1 >= s2 && s1 <= e2) return true;
    
    return false;
};