// 태스크 프리셋 관리 유틸리티
const PRESET_STORAGE_KEY = 'task_presets';

// 프리셋 저장
export const savePreset = (name, steps) => {
  try {
    const existingPresets = getPresets();
    const newPreset = {
      id: Date.now().toString(),
      name: name,
      steps: steps.map(step => ({
        id: step.id,
        stepType: step.stepType,
        order: step.order,
        // 이동 스텝 관련 필드
        stationId: step.stationId,
        stationName: step.stationName,
        x: step.x,
        y: step.y,
        type: step.type,
        // 대기 스텝 관련 필드
        waitTime: step.waitTime,
        waitCondition: step.waitCondition,
        // 작업 스텝 관련 필드
        workDescription: step.workDescription
      })),
      createdAt: new Date().toISOString(),
      stepsCount: steps.length
    };
    
    const updatedPresets = [...existingPresets, newPreset];
    localStorage.setItem(PRESET_STORAGE_KEY, JSON.stringify(updatedPresets));
    return { success: true, preset: newPreset };
  } catch (error) {
    console.error('프리셋 저장 실패:', error);
    return { success: false, error: error.message };
  }
};

// 프리셋 목록 가져오기
export const getPresets = () => {
  try {
    const stored = localStorage.getItem(PRESET_STORAGE_KEY);
    return stored ? JSON.parse(stored) : [];
  } catch (error) {
    console.error('프리셋 로드 실패:', error);
    return [];
  }
};

// 프리셋 불러오기
export const loadPreset = (presetId) => {
  try {
    const presets = getPresets();
    const preset = presets.find(p => p.id === presetId);
    if (!preset) {
      return { success: false, error: '프리셋을 찾을 수 없습니다.' };
    }
    
    // 새로운 ID로 스텝들을 복사 및 이전 버전 호환성 처리
    const steps = preset.steps.map(step => {
      const newStep = {
        ...step,
        id: Date.now() + Math.random() // 고유 ID 생성
      };
      
      // 이전 버전 호환성: nodeName이 있으면 stationName으로 변환
      if (step.nodeName && !step.stationName) {
        newStep.stationName = step.nodeName;
      }
      
      return newStep;
    });
    
    return { success: true, steps, preset };
  } catch (error) {
    console.error('프리셋 로드 실패:', error);
    return { success: false, error: error.message };
  }
};

// 프리셋 삭제
export const deletePreset = (presetId) => {
  try {
    const presets = getPresets();
    const updatedPresets = presets.filter(p => p.id !== presetId);
    localStorage.setItem(PRESET_STORAGE_KEY, JSON.stringify(updatedPresets));
    return { success: true };
  } catch (error) {
    console.error('프리셋 삭제 실패:', error);
    return { success: false, error: error.message };
  }
};

// 프리셋 이름 변경
export const renamePreset = (presetId, newName) => {
  try {
    const presets = getPresets();
    const presetIndex = presets.findIndex(p => p.id === presetId);
    if (presetIndex === -1) {
      return { success: false, error: '프리셋을 찾을 수 없습니다.' };
    }
    
    presets[presetIndex].name = newName;
    localStorage.setItem(PRESET_STORAGE_KEY, JSON.stringify(presets));
    return { success: true, preset: presets[presetIndex] };
  } catch (error) {
    console.error('프리셋 이름 변경 실패:', error);
    return { success: false, error: error.message };
  }
}; 